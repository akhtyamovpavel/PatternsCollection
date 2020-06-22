from routers import Router
from routers import WiFiRouter
from routers.FourRouter import FourRouter


def main():
    print('Connection via 4g')
    hub: Router = FourRouter()
    hub_status = hub.connect_to_net()

    print(hub_status)

    print('Connection via WiFi Router')
    wifi_router: Router = WiFiRouter()
    wifi_router_status = wifi_router.connect_to_net()
    print(wifi_router_status)


if __name__ == '__main__':
    main()
