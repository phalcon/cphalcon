<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use Phalcon\Di\FactoryDefault;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diFactorydefaultConstruct(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault - __construct()');
        $container = new FactoryDefault();
        $services  = $this->getServices();

        $expected = count($services);
        $actual   = count($container->getServices());
        $I->assertEquals($expected, $actual);
    }

    private function getServices(): array
    {
        return [
            'annotations'        => 'Phalcon\Annotations\Adapter\Memory',
            'assets'             => 'Phalcon\Assets\Manager',
            'crypt'              => 'Phalcon\Crypt',
            'cookies'            => 'Phalcon\Http\Response\Cookies',
            'dispatcher'         => 'Phalcon\Mvc\Dispatcher',
            'escaper'            => 'Phalcon\Escaper',
            'eventsManager'      => 'Phalcon\Events\Manager',
            'flash'              => 'Phalcon\Flash\Direct',
            'flashSession'       => 'Phalcon\Flash\Session',
            'filter'             => 'Phalcon\Filter\FilterLocator',
//            'filter'             => 'Phalcon\Filter',
            'modelsManager'      => 'Phalcon\Mvc\Model\Manager',
            'modelsMetadata'     => 'Phalcon\Mvc\Model\MetaData\Memory',
            'request'            => 'Phalcon\Http\Request',
            'response'           => 'Phalcon\Http\Response',
            'router'             => 'Phalcon\Mvc\Router',
            'security'           => 'Phalcon\Security',
            'tag'                => 'Phalcon\Tag',
            'transactionManager' => 'Phalcon\Mvc\Model\Transaction\Manager',
            'url'                => 'Phalcon\Url',
        ];
    }

    /**
     * Tests Phalcon\Di\FactoryDefault :: __construct() - Check services
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diFactoryDefaultConstructServices(UnitTester $I)
    {
        $I->wantToTest('Di\FactoryDefault - __construct() - Check services');
        $container = new FactoryDefault();
        $services  = $this->getServices();

        foreach ($services as $service => $class) {
            $params = null;
            if ('sessionBag' === $service) {
                $params = ['someName'];
            }
            $expected = get_class($container->get($service, $params));
            $actual   = $class;
            $I->assertEquals($expected, $actual);
        }
    }
}
