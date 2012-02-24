<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

error_reporting(E_ALL | E_NOTICE | E_STRICT);

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

require 'tests/autoload.php';

$view = new Phalcon_View();
$view->setViewsDir('tests/views/');

if($view->getViewsDir()=='tests/views/'){
	echo 'Phalcon_View::setViewsDir() [OK]', PHP_EOL;
} else {
	echo 'Phalcon_View::setViewsDir() [FAILED]', PHP_EOL;
	return;
}

$view->start();
$view->render('test2', 'index');
$view->finish();

if($view->getContent()=='here'){
	echo 'Phalcon_View::render() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_View::render() [1] [FAILED]', PHP_EOL;
	return;
}

$view->start();
$view->render('test3', 'other');
$view->finish();

if($view->getContent()=='lolhere'){
	echo 'Phalcon_View::render() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_View::render() [2] [FAILED]', PHP_EOL;
	return;
}

$view->setParamToView('born', 'this');

$view->start();
$view->render('test3', 'another');
$view->finish();

if($view->getContent()=='lolthis'){
	echo 'Phalcon_View::setParamToView() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_View::setParamToView() [1] [FAILED]', PHP_EOL;
	return;
}

$view->setTemplateAfter('test');

$view->start();
$view->render('test3', 'other');
$view->finish();

if($view->getContent()=='zuplolhere'){
	echo 'Phalcon_View::setTemplateAfter() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_View::setTemplateAfter() [1] [FAILED]', PHP_EOL;
	return;
}