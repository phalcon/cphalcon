<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Paginator\PaginatorFactory;

use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Paginator\PaginatorFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Traits\FactoryTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class LoadTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use FactoryTrait;

    public function setUp(): void
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Translate\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testPaginatorPaginatorFactoryLoadArray(): void
    {
        $this->setNewFactoryDefault();

        $modelsManager = $this->container->get('modelsManager');
        $options       = $this->arrayConfig['paginator'];

        $options['options']['builder'] = $modelsManager
            ->createBuilder()
            ->columns('id,name')
            ->from('Invoices')
            ->orderBy('name')
        ;

        $factory = new PaginatorFactory();
        $adapter = $factory->load($options);

        $this->assertInstanceOf(QueryBuilder::class, $adapter);
    }

    /**
     * Tests Phalcon\Translate\Factory :: load() - Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testPaginatorPaginatorFactoryLoadConfig(): void
    {
        $this->setNewFactoryDefault();

        $modelsManager = $this->container->get('modelsManager');
        $options       = $this->config->paginator;

        $options->options->builder = $modelsManager
            ->createBuilder()
            ->columns('id,name')
            ->from('Invoices')
            ->orderBy('name')
        ;

        $factory = new PaginatorFactory();

        $adapter = $factory->load($options);

        $this->assertInstanceOf(QueryBuilder::class, $adapter);
    }
}
