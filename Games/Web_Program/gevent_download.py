import gevent
import urllib.request
from gevent import monkey

monkey.patch_all()


def downloader(img_name, img_url):
    req = urllib.request.urlopen(img_url)

    img_content = req.read()

    with open(img_name, "wb") as f:
        f.write(img_content)


def main():
    gevent.joinall(
        [gevent.spawn(downloader, "1.jpg",
                      "https://dn-simplecloud.shiyanlou.com/1500460827398.png"),
         gevent.spawn(downloader, "2.jpg",
                      "https://dn-simplecloud.shiyanlou.com/courses/uid8504-20190712-1562930274699"),
         gevent.spawn(downloader, "3.jpg", "https://dn-simplecloud.shiyanlou.com/ncn1.jpg")])


if __name__ == "__main__":
    main()
