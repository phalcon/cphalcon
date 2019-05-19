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

namespace Phalcon\Test\Integration\Paginator\PaginatorFactory;

use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use Phalcon\Paginator\PaginatorFactory;
use IntegrationTester;

class LoadCest
{
    use DiTrait;
    use FactoryTrait;

    public function _before(IntegrationTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Translate\Factory :: load() - Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function translateFactoryLoadConfig(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\AdapterFactory - load() - Config');

        $this->setNewFactoryDefault();

        $options = $this->config->paginator;

        $options->options->builder = $this
            ->container
            ->get('modelsManager')
            ->createBuilder()
            ->columns('id,name')
            ->from('Robots')
            ->orderBy('name')
        ;


        $factory = new PaginatorFactory();
        $adapter = $factory->load($options);

        $I->assertInstanceOf(
            QueryBuilder::class,
            $adapter
        );
    }

    /**
     * Tests Phalcon\Translate\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function translateFactoryLoadArray(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\AdapterFactory - load() - array');

        $options = $this->arrayConfig['paginator'];

        $options['options']['builder'] = $this
            ->container
            ->get('modelsManager')
            ->createBuilder()
            ->columns('id,name')
            ->from('Robots')
            ->orderBy('name')
        ;

        $factory = new PaginatorFactory();
        $adapter = $factory->load($options);

        $I->assertInstanceOf(
            QueryBuilder::class,
            $adapter
        );
    }
}
