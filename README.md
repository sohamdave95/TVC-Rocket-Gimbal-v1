# TVC Rocket Gimbal

A fully custom 3D-printed thrust-vector-control (TVC) gimbal for a model rocket motor — real-time gyroscope-driven actuation using an MPU6050 and RC servos.

🎥 [Watch it in action on YouTube](https://www.youtube.com/watch?v=dMqgMUTd--s)

---

## What is TVC?

Thrust Vector Control is how modern rockets steer without aerodynamic fins — by physically pivoting the engine nozzle to redirect thrust. It's the same principle behind:

- SpaceX Falcon 9 / Starship first-stage steering
- Model and amateur rocketry active stabilization
- Gimbaled thruster attitude control on spacecraft

Unlike fin-based stabilization, TVC works even before the rocket has airspeed — making it essential for the first critical moments off the pad.

---

## System Overview

| Component | Detail |
|---|---|
| Microcontroller | ESP32 |
| IMU | MPU6050 (accelerometer + gyroscope) |
| Actuation | 2x RC servos via pushrods |
| Gimbal Mount | Custom 3D printed, 2-axis pivot |
| Linkage | Direct pushrod attachment to gimbal mounting points |
| Frame | 3D printed |

---

## Control Architecture

### Orientation-to-Gimbal Mapping

The MPU6050 is mounted so its orientation mirrors the rocket's body frame. Pitch and roll angles read from the IMU are mapped directly to the two gimbal axes, so as the "rocket" tips, the gimbal counters it — the same feedback relationship a real TVC-stabilized rocket uses to fight disturbances in flight.

Key implementation details:
- **Real-time angle reads** — continuous pitch/roll sampling from the MPU6050
- **Servo pushrod linkage** — converts servo horn rotation into precise gimbal deflection through direct mechanical pushrods
- **Direct angle-to-actuation mapping** — IMU angle drives servo position, mirroring rocket attitude in real time

---

## Known Limitations

- **Open-loop actuation** — servo response currently maps directly to IMU angle rather than running through a closed-loop controller (e.g. PID) — no active correction for overshoot or oscillation yet
- **No thrust integration** — this is a mechanical + sensing demo; it isn't yet paired with a live motor burn
- **No filtering on raw IMU data** — a complementary or Kalman filter would reduce noise sensitivity

---

## Repository Structure
TVC-Rocket-Gimbal-v1/
├── STLs Folder - Print at: 220C, 60C bed temp, Elegoo PLA+
├── main.cpp # Firmware — MPU6050 reads + servo actuation
└── README.md

---

## What's Next

- [ ] Closed-loop PID stabilization instead of direct angle mapping
- [ ] Static test stand fire with live motor


---

## Contact Me

📧 davesoh929@gmail.com | [GitHub](https://github.com/sohamdave95) | [Medium](https://medium.com/@davesoh929)

---

**Topics:** `thrust-vector-control` `tvc` `rocketry` `model-rocket` `mpu6050` `gimbal` `esp32` `servo-control` `3d-printing` `embedded-systems` `robotics` `aerospace` `attitude-control` `gyroscope`
