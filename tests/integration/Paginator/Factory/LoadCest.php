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

namespace Phalcon\Test\Integration\Paginator\Factory;

use IntegrationTester;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Paginator\Factory;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;

/**
 * Class LoadCest
 */
class LoadCest
{
    use FactoryTrait;
    use DiTrait;

    /**
     * Tests Phalcon\Paginator\Factory :: load() - Config
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function paginatorFactoryLoadConfig(IntegrationTester $I)
    {
        $I->wantToTest("Paginator\Factory - load() - Config");
        $I->skipTest("TODO: need to check this");
        $this->setNewFactoryDefault();
        $options          = $this->config->paginator;
        $options->builder = $this
            ->container
            ->get('modelsManager')
            ->createBuilder()
            ->columns("id,name")
            ->from("Robots")
            ->orderBy("name")
        ;
        /** @var QueryBuilder $paginator */
        $paginator = Factory::load($options);
        $I->assertInstanceOf(QueryBuilder::class, $paginator);
        $I->assertEquals($options->limit, $paginator->getLimit());
        $I->assertEquals($options->page, $paginator->getCurrentPage());
    }

    /**
     * Tests Phalcon\Paginator\Factory :: load() - array
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function paginatorFactoryLoadArray(IntegrationTester $I)
    {
        $I->wantToTest("Paginator\Factory - load() - array");
        $I->skipTest("TODO: need to check this");
        $this->setNewFactoryDefault();
        $options            = $this->arrayConfig["paginator"];
        $options["builder"] = $this
            ->container
            ->get('modelsManager')
            ->createBuilder()
            ->columns("id,name")
            ->from("Robots")
            ->orderBy("name")
        ;
        /** @var QueryBuilder $paginator */
        $paginator = Factory::load($options);
        $I->assertInstanceOf(QueryBuilder::class, $paginator);
        $I->assertEquals($options["limit"], $paginator->getLimit());
        $I->assertEquals($options["page"], $paginator->getCurrentPage());
    }
}
