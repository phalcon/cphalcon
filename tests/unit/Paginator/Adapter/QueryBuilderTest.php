<?php

namespace Phalcon\Test\Unit\Paginator\Adapter;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Paginator\Adapter\QueryBuilder;
use Phalcon\Mvc\Model\Metadata\Memory;

/**
 * \Phalcon\Test\Unit\Paginator\Adapter\QueryBuilderTest
 * Tests the \Phalcon\Paginator\Adapter\QueryBuilder component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Paginator\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class QueryBuilderTest extends UnitTest
{

    /**
     * @var Manager
     */
    private $modelsManager;

    /**
     * @var Manager
     */
    private $builder;

    /**
     * Executed before each test
     *
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        Di::setDefault($I->getApplication()->getDI());

        $this->modelsManager = $I->getApplication()->getDI()->getShared('modelsManager');

        $I->haveServiceInDi('modelsMetadata', function() {
            return new Memory;
        }, true);

        $this->builder = $this->modelsManager->createBuilder()
            ->columns('sel_id, sel_name')
            ->from('Phalcon\Test\Models\Select')
            ->orderBy('sel_name');
    }

    /**
     * Tests QueryBuilder constructor
     *
     * @since  2016-27-07
     */
    public function testShouldCreatePaginator()
    {
        $this->specify(
            "QueryBuilder does not create expected object for page 1",
            function () {
                $paginator = new QueryBuilder(
                    [
                        "builder"  => $this->builder,
                        "limit" => 2,
                        "page"  => 1
                    ]
                );

                $page = $paginator->getPaginate();

                expect($page)->isInstanceOf('stdClass');
                expect($page->items)->count(2);

                expect($page->before)->equals(1);
                expect($page->next)->equals(2);
                expect($page->last)->equals(4);
                expect($page->limit)->equals(2);

                expect($page->current)->equals(1);
                expect($page->total_pages)->equals(4);
            }
        );

        $this->specify(
            "QueryBuilder does not create expected object for page 2",
            function () {
                $paginator = new QueryBuilder(
                    [
                        "builder"  => $this->builder,
                        "limit" => 2,
                        "page"  => 2
                    ]
                );

                $page = $paginator->getPaginate();

                expect($page)->isInstanceOf('stdClass');
                expect($page->items)->count(2);

                expect($page->before)->equals(1);
                expect($page->next)->equals(3);
                expect($page->last)->equals(4);
                expect($page->limit)->equals(2);

                expect($page->current)->equals(2);
                expect($page->total_pages)->equals(4);
            }
        );

        $this->specify(
            "QueryBuilder does not create expected object for page 3",
            function () {
                $paginator = new QueryBuilder(
                    [
                        "builder"  => $this->builder,
                        "limit" => 2,
                        "page"  => 3
                    ]
                );

                $page = $paginator->getPaginate();

                expect($page)->isInstanceOf('stdClass');
                expect($page->items)->count(2);

                expect($page->before)->equals(2);
                expect($page->next)->equals(4);
                expect($page->last)->equals(4);
                expect($page->limit)->equals(2);

                expect($page->current)->equals(3);
                expect($page->total_pages)->equals(4);
            }
        );
    }

    /**
     * Tests QueryBuilder::setCurrentPage
     *
     * @since  2016-27-07
     */
    public function testShouldSetCurrentPage()
    {
        $this->specify(
            "NativeArray::setCurrentPage does not work correctly",
            function () {
                $paginator = new QueryBuilder(
                    [
                        "builder"  => $this->builder,
                        "limit" => 2,
                        "page"  => 3
                    ]
                );

                $paginator->setCurrentPage(2);

                $page = $paginator->getPaginate();

                expect($page)->isInstanceOf('stdClass');
                expect($page->items)->count(2);

                expect($page->before)->equals(1);
                expect($page->next)->equals(3);
                expect($page->last)->equals(4);
                expect($page->limit)->equals(2);

                expect($page->current)->equals(2);
                expect($page->total_pages)->equals(4);
            }
        );
    }

    /**
     * Tests QueryBuilder totalCount config
     *
     * @since  2016-27-07
     */
    public function testTotalCountConfig()
    {
        $this->specify(
            "QueryBuilder totalCount config does not work correctly page 1",
            function () {
                $paginator = new QueryBuilder(
                    [
                        "builder"  => $this->builder,
                        "limit" => 4,
                        "page"  => 1,
                        "totalCount" => 100
                    ]
                );

                $page = $paginator->getPaginate();

                expect($page)->isInstanceOf('stdClass');
                expect($page->items)->count(4);

                expect($page->before)->equals(1);
                expect($page->next)->equals(2);
                expect($page->last)->equals(25);
                expect($page->limit)->equals(4);

                expect($page->current)->equals(1);
                expect($page->total_pages)->equals(25);
            }
        );

        $this->specify(
            "QueryBuilder totalCount config does not work correctly page 2",
            function () {
                $paginator = new QueryBuilder(
                    [
                        "builder"  => $this->builder,
                        "limit" => 4,
                        "page"  => 2,
                        "totalCount" => 100
                    ]
                );

                $page = $paginator->getPaginate();

                expect($page)->isInstanceOf('stdClass');
                expect($page->items)->count(4);

                expect($page->before)->equals(1);
                expect($page->next)->equals(3);
                expect($page->last)->equals(25);
                expect($page->limit)->equals(4);

                expect($page->current)->equals(2);
                expect($page->total_pages)->equals(25);
            }
        );
    }
}
