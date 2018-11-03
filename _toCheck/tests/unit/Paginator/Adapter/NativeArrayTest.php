<?php

namespace Phalcon\Test\Unit\Paginator\Adapter;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Paginator\Adapter\NativeArray;

/**
 * \Phalcon\Test\Unit\Paginator\Adapter\NativeArrayTest
 * Tests the \Phalcon\Paginator\Adapter\NativeArray component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Paginator\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class NativeArrayTest extends UnitTest
{

    /**
     * Tests NativeArray constructor
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testShouldCreatePaginator()
    {
        $this->specify(
            "NativeArray does not create expected object",
            function () {
                $paginator = new NativeArray(
                    [
                        'data'  => array_fill(0, 30, 'banana'),
                        'limit' => 25,
                        'page'  => 1
                    ]
                );

                $page = $paginator->getPaginate();

                expect($page)->isInstanceOf('stdClass');
                expect($page->items)->count(25);

                expect($page->previous)->equals(1);
                expect($page->before)->equals(1);
                expect($page->next)->equals(2);
                expect($page->last)->equals(2);
                expect($page->limit)->equals(25);

                /**
                 * Now check by calling 'paginate()'
                 */
                $page = $paginator->paginate();

                expect($page)->isInstanceOf('stdClass');
                expect($page->items)->count(25);

                expect($page->previous)->equals(1);
                expect($page->before)->equals(1);
                expect($page->next)->equals(2);
                expect($page->last)->equals(2);
                expect($page->limit)->equals(25);

                expect($page->current)->equals(1);
                expect($page->total_pages)->equals(2);

                expect($page->current)->equals(1);
                expect($page->total_pages)->equals(2);
            }
        );
    }

    /**
     * Tests NativeArray::setCurrentPage
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-03-03
     */
    public function testShouldSetCurrentPage()
    {
        $this->specify(
            "NativeArray::setCurrentPage does not work correctly",
            function () {
                $paginator = new NativeArray(
                    [
                        'data'  => array_fill(0, 30, 'banana'),
                        'limit' => 25,
                        'page'  => 1
                    ]
                );

                $paginator->setCurrentPage(2);

                $page = $paginator->getPaginate();

                expect($page)->isInstanceOf('stdClass');
                expect($page->items)->count(5);

                expect($page->before)->equals(1);
                expect($page->next)->equals(2);
                expect($page->last)->equals(2);

                expect($page->current)->equals(2);
                expect($page->total_pages)->equals(2);
            }
        );
    }
}
