<?php

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di\FactoryDefault;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Di\FactoryDefaultTest
 * Tests the \Phalcon\Di\FactoryDefault component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Di
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FactoryDefaultTest extends UnitTest
{
    /**
     * Tests FactoryDefault
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testFactoryDefault()
    {
        $this->specify(
            "FactoryDefault does not contains the expected services",
            function ($name, $class) {
                $params = null;
                $factoryDefault = new FactoryDefault();

                if ('sessionBag' === $name) {
                    $params = ['someName'];
                }

                expect(get_class($factoryDefault->get($name, $params)))->equals($class);
            },
            ['examples' => [
                ['router', 'Phalcon\Mvc\Router'],
                ['dispatcher', 'Phalcon\Mvc\Dispatcher'],
                ['url', 'Phalcon\Mvc\Url'],
                ['modelsManager', 'Phalcon\Mvc\Model\Manager'],
                ['modelsMetadata', 'Phalcon\Mvc\Model\MetaData\Memory'],
                ['response', 'Phalcon\Http\Response'],
                ['cookies', 'Phalcon\Http\Response\Cookies'],
                ['request', 'Phalcon\Http\Request'],
                ['filter', 'Phalcon\Filter'],
                ['escaper', 'Phalcon\Escaper'],
                ['security', 'Phalcon\Security'],
                ['crypt', 'Phalcon\Crypt'],
                ['annotations', 'Phalcon\Annotations\Adapter\Memory'],
                ['flash', 'Phalcon\Flash\Direct'],
                ['flashSession', 'Phalcon\Flash\Session'],
                ['tag', 'Phalcon\Tag'],
                ['session', 'Phalcon\Session\Adapter\Files'],
                ['sessionBag', 'Phalcon\Session\Bag'],
                ['eventsManager', 'Phalcon\Events\Manager'],
                ['transactionManager', 'Phalcon\Mvc\Model\Transaction\Manager'],
                ['assets', 'Phalcon\Assets\Manager'],
            ]]
        );
    }
}
