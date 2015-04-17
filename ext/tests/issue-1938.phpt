--TEST--
Bugs in href Phalcon\Mvc\Url or Phalcon\Mvc\Router - https://github.com/phalcon/cphalcon/issues/1938
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();

$di['url'] = function () {

    $url = new \Phalcon\Mvc\Url();
    $url->setBasePath('/example/');
    $url->setBaseUri('/');

    return $url;
};

$router = new Phalcon\Mvc\Router();
$router->add('/test/')->setName('test-00');
$router->add('/test/{id}')->setName('test-0');

class TestRoute extends \Phalcon\Mvc\Router\Group
{
    public function initialize()
    {
        $this->setPrefix('/test-class/');
        $this->add('/test/{id:\d}')->setName('test-5');
    }
}

class TestRoute2 extends \Phalcon\Mvc\Router\Group
{
    public function initialize()
    {
        $this->add('/test/{id:\d}')->setName('test-6');
    }
}

$router->mount(new TestRoute);
$router->mount(new TestRoute2);

$di['router'] = $router;

echo $di['url']->get(array('for' => 'test-00')), PHP_EOL;
echo $di['url']->get(array('for' => 'test-0', 'id' => 'none')), PHP_EOL;
echo $di['url']->get(array('for' => 'test-0')), PHP_EOL;
echo $di['url']->get(array('for' => 'test-5', 'id' => 1)), PHP_EOL;
echo $di['url']->get(array('for' => 'test-5')), PHP_EOL;
echo $di['url']->get(array('for' => 'test-6', 'id' => 1)), PHP_EOL;
echo $di['url']->get(array('for' => 'test-6')), PHP_EOL;
?>
--EXPECT--
/test/
/test/none
/test/
/test-class/test/1
/test-class/test/
/test/1
/test/
