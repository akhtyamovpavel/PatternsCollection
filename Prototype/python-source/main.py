from typing import List
from Prototype import Prototype
from FerrariPrototype import FerrariPrototype
from PirelliFerrari import PirelliFerrari


if __name__ == '__main__':
    machine = PirelliFerrari("Pirelli", "Ferrari")
    prototype = FerrariPrototype("BMW")

    machines: List[Prototype] = [machine, prototype]

    clones = [
        machine.clone() for machine in machines
    ]

    for machine in machines:
        print(machine.engine_name)
        try:
            print(machine.chassis_name)
        except AttributeError:
            print('Could not be casted to PirelliFerrari')
