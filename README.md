Phalcon Framework
=================

### 该分支增加的新特性：

* \Phalcon\Utils\Arr -- Array functions. Get an array key or default to a set value, get an array key by path, etc.
* \Phalcon\Utils\Date -- Useful date functions and constants. Time between two dates, convert between am/pm and military, date offset, etc.
* \Phalcon\Http\Client -- HTTP protocol client.
* \Phalcon\Chart\QRcode -- QR Code Generator and Scanner.
* \Phalcon\Utils\Scws -- Chinese word segmentation.

```php
// Example 1: HTTP Request
$client = new \Phalcon\Http\Client($url, 'POST');

// Set post/put/other data
$client->setData($data);

// Upload file
//$client->setFiles(array('phalconphp.jpg'));

$ret = $client->send();
if ($ret) {
	echo $client->getResponseHeaders();
	echo $client->getResponseCookies();
	echo $client->getResponseBody();
	echo $client->getResponseCode();
	echo $client->getResponseStatus()
}

// Example 2: QR Code generate
$str = 'Phalcon is web framework';

$qr = new \Phalcon\Chart\QRcode();
$ret = $qr->generate($str);

if ($ret) {
	$qr->save('qr.png')
}

// Example 3: QR Code add logo
$qr = new \Phalcon\Chart\QRcode();

if ($qr->generate('欢迎使用 PhalconPHP', 1, \Phalcon\Chart\QRcode::LEVEL_H)) {
	$ret = $qr->save('qr.png', 5, 1);

	$logo = new \Phalcon\Image\Adapter\Imagick('logo.png');
	$logo->resize(40, 40);

	$image = new \Phalcon\Image\Adapter\Imagick('qr.png');
	$image->watermark($logo);
	$image->save('qr2.png');
}

// QR Code reader
$ret = $qr->scan('qr.png');

// Example 4: Set QR Code Color
$qr = new \Phalcon\Chart\QRcode();

$ret = $qr->generate($str);
if ($ret) {
	$qr->save('qr.png', NULL, NULL, 'FFCC00', '000000');
	header("Content-type: image/PNG");
	echo $qr->render(NULL, NULL, 'FFCC00', '000000');
}

// Example 5: Chinese word segmentation
$scws = new Phalcon\Utils\Scws('utf8');
$scws->set_dict("/var/www/dict.utf8.xdb");
$scws->set_rule("/var/www/rule.utf8.ini");
$scws->send_text("我是一个中国人,我会C++语言,我也有很多T恤衣服");
$tops = $scws->get_tops(5);
$tmp = '';
foreach($tops as $top) {
	$tmp = $tmp ? $tmp.'|'.$top['word'] : $top['word'];
}
print_r($tmp);
$tmp = '';
while ($tops = $scws->get_result())
{
	foreach($tops as $top) {
	    $tmp = $tmp ? $tmp.'|'.$top['word'] : $top['word'];
	}
}
print_r($tmp);
exit;
```

Volt Filters
------------
```php
{{ "PhalconPHP"|fcall('str_replace', 2, 'PHP', '') }} // Phalcon
{{ "PhalconPHP"|fcall('str_pad', 0, 5, '=') }}	// PhalconPHP=====
```

关闭QRcode支持
```shell
phpize
./configure enable_qrcode=no
make && make test
```

Phalcon 是一款开源的Web框架，用C语言开发的PHP扩展，旨在提高性能并减少资源消耗。

开始使用
--------

Phalcon 具有跨平台的特性. 因此, Phalcon 可安装于 Microsoft Windows、GNU/Linux、Mac OS X等平台，您可以选择下载相关平台的二进制文件或者通过源码编译得到。

### Windows

在 Windows 平台使用，下载 DLL 库 ( http://phalconphp.com/download )。编辑 php.ini 文件增加如下内容：

```bash
extension=php_phalcon.dll
```

最后重启Web服务。

### Linux/Unix/Mac

在基于 Unix 的平台，您可以很容易的使用源码编译和安装。

#### Requirements
我们需要提前安装一些库和软件

* PHP 5.x 开发库
* GCC 编译器
* libqrencode-dev、libzbar-dev、libpng-dev、libpng-dev、libmagickwand-dev (可选)

Ubuntu:

```bash
sudo apt-get install php5-dev php5-mysql gcc make
```

Suse:

```bash
yast2 -i php5-pear php5-devel libmysqlclient gcc make autoconf2.13
```

编译
----

按照下面的步骤为您的平台生成扩展文件：

```bash
git clone git://github.com/phalcon/cphalcon.git
cd cphalcon/build
sudo ./install
```

添加扩展到您的 php.ini 文件：

```bash
extension=phalcon.so
```

最后重启Web服务。

External Links
--------------

* [Documentation](http://docs.phalconphp.com/)
* [Support](http://phalconphp.com/support)
* [Blog](http://blog.phalconphp.com)
* [Twitter](http://twitter.com/phalconphp)

Current Build Status
--------------------

Phalcon Framework is built under Travis CI service. Every commit pushed to this repository will queue a build into the continuous integration service and will run all PHPUnit tests to ensure that everything is going well and the project is stable. The current build status is:

[![Build Status](https://secure.travis-ci.org/phalcon/cphalcon.png?branch=master)](http://travis-ci.org/phalcon/cphalcon)

License
-------
Phalcon is open-sourced software licensed under the New BSD License. See the docs/LICENSE.txt file for more information.
