--TEST--
Segmentation Fault in ViewSimpleTest::testRenderWithCache (run under valgrind) - https://github.com/phalcon/cphalcon/issues/1607
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$view = new \Phalcon\Mvc\View\Simple;
$view->setViewsDir(__DIR__ . '/views/');

function getdi()
{
	$di = new \Phalcon\Di;
	$frontendCache = new \Phalcon\Cache\Frontend\Output(array('lifetime' => 2));
	$backendCache  = new \Phalcon\Cache\Backend\Memory($frontendCache);
	$di->set('viewCache', $backendCache);
	return $di;
}

$di = getdi();
$view->setDI($di);
$view->cache(array('key' => 'view_simple_cache'));

$cache = $view->getCache();
$timeNow = time();
$view->setParamToView('a_cool_var', $timeNow);
$view->render('coolVar');
gc_collect_cycles();
unset($view, $cache);
?>
--EXPECT--
