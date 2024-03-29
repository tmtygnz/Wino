#pragma once
enum ANIKAPhases {
    core_setup,
    test_sensors,
    move,
    move_left,
    move_right,
    move_around,
    stop,
    hydraulic_base_up,
    hydraulic_base_down,
    hydraulic_frontal_up,
    hydraulic_frontal_down,
};

void SetupPins();