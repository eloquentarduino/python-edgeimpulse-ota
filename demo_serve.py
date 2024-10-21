from edgeimpulse_ota import serve


if __name__ == '__main__':
    # local file
    ota_payload, size = serve(zip="data/ei.zip")
    print(f"const uint8_t ota[{size}] = {{", ", ".join("%d" % b for b in ota_payload), "}")

    with open("data/ota.bin", "wb") as f:
        f.write(ota_payload)

    # API
    api_key = "ei_59e01e8cdef245c00a1e5f654f978f806ecebe5f2c58d68b"
    project_id = "508852"
    ota_payload, size = serve(api_key=api_key, project_id=project_id, engine="tflite-eon")
    print(f"const uint8_t ota[{size}] = {{", ", ".join("%d" % b for b in ota_payload), "}")
