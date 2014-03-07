--TEST--
FlashSession does not automatically set the custom CSS classes from constructor argument - https://github.com/phalcon/cphalcon/issues/2136#issuecomment-37016079
--SKIPIF--
<?php include('skipif.inc'); ?>
--GET--
dummy=1
--FILE--
<?php
$di = new \Phalcon\DI();
$di->setShared('session', function() {
	$session = new \Phalcon\Session\Adapter\Files();
	$session->start();
	return $session;
});

$di->set('flash', function() {
	return new Phalcon\Flash\Direct(array(
		'error'   => 'alert alert-error',
		'success' => 'alert alert-success',
		'notice'  => 'alert alert-info',
	));
});

$di->set('flashSession', function() {
	return new Phalcon\Flash\Session(array(
		'error'   => 'alert alert-error',
		'success' => 'alert alert-success',
		'notice'  => 'alert alert-info',
	));
});

$di->get('flash')->error('Error');
$di->getShared('flashSession')->notice('Notice');
$di->getShared('flashSession')->output();
?>
--EXPECT--
<div class="alert alert-error">Error</div>
<div class="alert alert-info">Notice</div>
