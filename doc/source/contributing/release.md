# Release Process

**This page is intended for admins of PyScreenReader.**

As a multi-platform project, our release process is slightly more complex.  
In general, the release process consists of two parts:
1. **Build Process**
2. **Publish Process**

These two steps must be executed in sequence but handled separately.

---

## Build Process
The build process generates wheels for multiple platforms and architectures, and uploads them to the staging environment: [Anaconda Staging](https://anaconda.org/Lmh-java/pyscreenreader).

To trigger the build process via GitHub Actions:
1. Navigate to **GitHub > Actions > Build Pipeline**.
2. Click **Run Workflow** in the top-right corner.
3. Provide the **version to release** and the **commit hash** to build from.
    - Follow the [Python Packaging User Guide](https://packaging.python.org/en/latest/discussions/versioning/) for versioning.
    - The commit hash must be a valid hash from the `main` branch.
4. Wait for all workflow jobs to succeed.
5. Verify that all wheels for the specified version are available in the Anaconda staging environment.

---

## Publish Process
**Note: The publish process requires a successful build process as a prerequisite.**

1. Confirm that the wheels for the release version exist in staging. When possible, perform manual end-to-end testing.
2. Navigate to **GitHub > Actions > Build Pipeline**.
3. Click **Run Workflow** in the top-right corner.
4. Provide the **version to release** and the **commit hash** to generate the release.
    - This commit hash is used to create the release notes.
    - Ensure it matches the commit hash used during the build process.
5. Decide whether to upload the artifacts to **PyPI**:
    - If checked, the workflow will upload to PyPI. Be cautious—versions uploaded to PyPI cannot be removed.
    - If unchecked, the workflow will upload to **TestPyPI**, which allows for a dry run and preview before the final release.
6. Once the workflow succeeds, go to **GitHub > Releases**. Review the draft release, revise the auto-generated changelog as needed, and then click **Publish**.

---
