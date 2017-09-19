<?php

namespace Phalcon\Test\Unit\Paginator;

use Helper\ModelTrait;
use Phalcon\Paginator\Factory;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Test\Unit\Factory\Helper\FactoryBase;

/**
 * \Phalcon\Test\Unit\Paginator\FactoryTest
 * Tests for \Phalcon\Paginator\Factory component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Annotations
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FactoryTest extends FactoryBase
{
    use ModelTrait;

    /**
     * Test factory using Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory()
    {
        $this->specify(
            "Factory using Phalcon\\Config doesn't work properly",
            function () {
                $options = $this->config->paginator;
                $options->builder = $this->setUpModelsManager()->createBuilder()
                    ->columns("id,name")
                    ->from("Robots")
                    ->orderBy("name");
                /** @var QueryBuilder $paginator */
                $paginator = Factory::load($options);
                expect($paginator)->isInstanceOf(QueryBuilder::class);
                expect($paginator->getLimit())->equals($options->limit);
                expect($paginator->getCurrentPage())->equals($options->page);
            }
        );
    }

    /**
     * Test factory using array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory()
    {
        $this->specify(
            "Factory using array doesn't work properly",
            function () {
                $options = $this->arrayConfig["paginator"];
                $options["builder"] = $this->setUpModelsManager()->createBuilder()
                    ->columns("id,name")
                    ->from("Robots")
                    ->orderBy("name");
                /** @var QueryBuilder $paginator */
                $paginator = Factory::load($options);
                expect($paginator)->isInstanceOf(QueryBuilder::class);
                expect($paginator->getLimit())->equals($options["limit"]);
                expect($paginator->getCurrentPage())->equals($options["page"]);
            }
        );
    }
}
