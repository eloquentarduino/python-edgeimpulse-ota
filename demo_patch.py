from edgeimpulse_ota import patch


if __name__ == '__main__':
    # local file
    patched_zip = patch(zip="data/ei.zip")

    with open("data/ei.patched.zip", "wb") as f:
        f.write(patched_zip)

    # API
    api_key = "ei_59e01e8cdef245c00a1e5f654f978f806ecebe5f2c58d68b"
    project_id = "508852"
    patched_api = patch(api_key=api_key, project_id=project_id, engine="tflite-eon")

    with open("data/ei.patched-api.zip", "wb") as f:
        f.write(patched_api)

