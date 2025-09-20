"""Performance benchmarks for widget operations."""

import timeit
import statistics
import pytest
from hypothesis import given, strategies as st
from PyScreenReader.virtual_widgets import VirtualButtonWidget, VirtualWidget, VirtualWindowWidget


def test_widget_creation_benchmark():
    """Benchmark the time to create widget instances."""

    def create_widgets():
        for _ in range(100):
            _ = VirtualButtonWidget()

    # Warm-up run
    create_widgets()

    # Measure performance
    times = timeit.repeat(create_widgets, number=1, repeat=5)

    # Calculate statistics
    mean_time = statistics.mean(times) * 1000  # Convert to milliseconds
    min_time = min(times) * 1000
    max_time = max(times) * 1000
    std_dev = statistics.stdev(times) * 1000 if len(times) > 1 else 0

    print(f"\nWidget Creation Benchmark (100 widgets):")
    print(f"  Mean time: {mean_time:.2f} ms")
    print(f"  Min time: {min_time:.2f} ms")
    print(f"  Max time: {max_time:.2f} ms")
    print(f"  Std dev: {std_dev:.2f} ms")

    # Assert that performance is within acceptable bounds
    assert mean_time < 10.0, "Widget creation is too slow"


def test_property_access_benchmark():
    """Benchmark the time to get/set widget properties."""
    button_widget = VirtualButtonWidget()

    def get_set_properties():
        for i in range(100):
            button_widget.set_title_text(f"Button {i}")
            button_widget.set_visible(i % 2 == 0)
            button_widget.set_x(i)
            button_widget.set_y(i * 2)
            _ = button_widget.get_title_text()
            _ = button_widget.is_visible()
            _ = button_widget.get_x()
            _ = button_widget.get_y()

    # Warm-up run
    get_set_properties()

    # Measure performance
    times = timeit.repeat(get_set_properties, number=1, repeat=5)

    # Calculate statistics
    mean_time = statistics.mean(times) * 1000  # Convert to milliseconds
    min_time = min(times) * 1000
    max_time = max(times) * 1000
    std_dev = statistics.stdev(times) * 1000 if len(times) > 1 else 0

    print(f"\nProperty Access Benchmark (100 iterations):")
    print(f"  Mean time: {mean_time:.2f} ms")
    print(f"  Min time: {min_time:.2f} ms")
    print(f"  Max time: {max_time:.2f} ms")
    print(f"  Std dev: {std_dev:.2f} ms")

    # Assert that performance is within acceptable bounds
    assert mean_time < 5.0, "Property access is too slow"


def test_memory_management():
    """Test that widgets are properly garbage collected."""
    import weakref

    # Create widget and weak reference
    widget = VirtualButtonWidget()
    ref = weakref.ref(widget)

    # Delete the only reference
    del widget

    # Widget should be garbage collected
    assert ref() is None


# Property-based tests using Hypothesis
# We are using VirtualButtonWidget as a concreate subclass of VirtualWidget to test with.
@given(
    title=st.text(max_size=100),
    help_text=st.text(max_size=200),
    x=st.integers(min_value=0, max_value=10000),
    y=st.integers(min_value=0, max_value=10000),
    width=st.integers(min_value=0, max_value=10000),
    height=st.integers(min_value=0, max_value=10000),
    visible=st.booleans(),
)
def test_widget_properties(
    title: str,
    help_text: str,
    x: int,
    y: int,
    width: int,
    height: int,
    visible: bool,
):
    button_widget = VirtualButtonWidget()
    """Test widget properties with generated test cases."""
    # Set properties
    button_widget.set_title_text(title)
    button_widget.set_help_text(help_text)
    button_widget.set_x(x)
    button_widget.set_y(y)
    button_widget.set_width(width)
    button_widget.set_height(height)
    button_widget.set_visible(visible)

    # Verify properties
    assert button_widget.get_title_text() == title
    assert button_widget.get_help_text() == help_text
    assert button_widget.get_x() == x
    assert button_widget.get_y() == y
    assert button_widget.get_width() == width
    assert button_widget.get_height() == height
    assert button_widget.is_visible() == visible
