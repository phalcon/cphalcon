--TEST--
Segmentation fault in zim_Phalcon_Mvc_Dispatcher__throwDispatchException - https://github.com/phalcon/cphalcon/issues/1258
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class Secure extends Phalcon\Mvc\User\Plugin
{
	public function beforeDispatch(\Phalcon\Events\Event $event, \Phalcon\Mvc\Dispatcher $dispatcher)
	{
		$acl = new \Phalcon\Acl\Adapter\Memory();
		$acl->setDefaultAction(Phalcon\Acl::ALLOW);
		$acl->addRole(new \Phalcon\Acl\Role('test'));

		$acl->isAllowed('test' , 'test' , 'test');
		$acl->isAllowed('test' , 'test' , 'test');
	}
}

$di = new \Phalcon\DI\FactoryDefault();
$di->set(
	'dispatcher',
	function () use ($di) {
		$eventsManager = $di->getShared('eventsManager');

		$secure = new \Secure($di);
		$eventsManager->attach('dispatch' , $secure);

		$dispatcher = new \Phalcon\Mvc\Dispatcher();
		$dispatcher->setEventsManager($eventsManager);

		return $dispatcher;
	}
);

$di['view'] = function(){
	return new Phalcon\Mvc\View();
};

$application = new \Phalcon\Mvc\Application($di);
try {
	$application->handle()->getContent();
}
catch (Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECT--
IndexController handler class cannot be loaded
