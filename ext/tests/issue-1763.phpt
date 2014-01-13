--TEST--
Fire dispatch:beforeException on exceptions from event handlers - https://github.com/phalcon/cphalcon/issues/1763
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

$di = new \Phalcon\DI\FactoryDefault();
$di->set('dispatcher', function() {
	$eventsManager = new Phalcon\Events\Manager;

	$eventsManager->attach('dispatch:beforeDispatchLoop', function($event, $dispatcher) {
		throw new Exception('Just because.');
	});

	$eventsManager->attach('dispatch:beforeException', function($event, $dispatcher, $exception) {
		while (ob_get_level()) {
			ob_end_clean();
		}

		echo 'dispatch:beforeException', PHP_EOL;
		ob_start();
	});

	$dispatcher = new Phalcon\Mvc\Dispatcher;
	$dispatcher->setEventsManager($eventsManager);

	return $dispatcher;
});

$di->set('view', 'Phalcon\\Mvc\\View');

$application = new \Phalcon\Mvc\Application($di);
echo $application->handle()->getContent();
echo 'After $application->handle()->getContent()', PHP_EOL;
?>
--EXPECT--
dispatch:beforeException
After $application->handle()->getContent()
