--TEST--
initialize() won't be invoked if event handler calls getShared() to get already initialized object - https://github.com/phalcon/cphalcon/issues/787
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

function dispatcherAutoloader($className)
{
	if (file_exists(__DIR__ . '/tasks/'.$className.'.php')) {
		require __DIR__ . '/tasks/'.$className.'.php';
	}
}

spl_autoload_register('dispatcherAutoloader');

$di = new \Phalcon\DI\FactoryDefault\CLI();

$di->setShared('dispatcher', function() use ($di)
{
	$dispatcher = new \Phalcon\CLI\Dispatcher;
	$dispatcher->setDI($di);
	return $dispatcher;
});

$console = new \Phalcon\CLI\Console();
$console->setDI($di);
$console->handle(array('task' => 'issue787', 'action' => 'main'));

var_dump(class_exists('Issue787Task'));

echo Issue787Task::$output;
?>
--EXPECT--
bool(true)
beforeExecuteRoute
initialize
