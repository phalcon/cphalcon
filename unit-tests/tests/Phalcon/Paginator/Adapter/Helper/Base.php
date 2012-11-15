<?php
/**
 * Base.php
 * Paginator_Adapter_Helper_Base
 *
 * Helper for the \Phalcon\Paginator\Adapter\* components
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class Paginator_Adapter_Helper_Base extends Phalcon_Test_ModelTestCase
{
    private $_class   = '';
    private $_params  = array();
    private $_fixture = null;
    
    public function setFixture($fixture)
    {
        $this->_fixture = $fixture;
    }
    
    public function setClass($class)
    {
        $this->_class = $class;
    }
    
    public function setParameters($page, $limit)
    {
        $this->_params = array(
                'data'  => $this->_fixture,
                'limit' => $limit,
                'page'  => $page,
            );
    }
    
    /**
     * Tests the returned class
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-05
     */
    public function testReturnedClass()
    {
        $class     = $this->_class;
        $paginator = new $class($this->_params);

        // Get a page
        $page = $paginator->getPaginate();

        $expected = 'stdClass';
        $actual   = get_class($page);

        $this->assertEquals($expected, $actual, 'Object returned not stdClass');
    }

    /**
     * Tests the count of the paginator items
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-05
     */
    public function testPageCount()
    {
        $class     = $this->_class;
        $paginator = new $class($this->_params);

        // Get a page
        $page = $paginator->getPaginate();

        $expected = 5;
        $actual   = count($page->items);

        $this->assertEquals($expected, $actual, 'Item count not correct');
    }

    /**
     * Tests the before, next, last, current, total_pages when on first page
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-05
     */
    public function testPageOneBeforeNextLastCurrentPages()
    {
        $class     = $this->_class;
        $paginator = new $class($this->_params);

        // Get a page
        $page = $paginator->getPaginate();

        $expected = 1;
        $actual   = $page->before;

        $this->assertEquals($expected, $actual, 'Before not correct');

        $expected = 2;
        $actual   = $page->next;

        $this->assertEquals($expected, $actual, 'Next not correct');

        $expected = 20;
        $actual   = $page->last;

        $this->assertEquals($expected, $actual, 'Last not correct');

        $expected = 1;
        $actual   = $page->current;

        $this->assertEquals($expected, $actual, 'Current not correct');

        $expected = 20;
        $actual   = $page->total_pages;

        $this->assertEquals($expected, $actual, 'Total Pages not correct');
    }

    /**
     * Tests the before, next, last, current, total_pages when on the middle
     * of the pagination collection
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-05
     */
    public function testPageMiddleBeforeNextLastCurrentPages()
    {
        $class     = $this->_class;
        $paginator = new $class($this->_params);

        $paginator->setCurrentPage(10);

        $page = $paginator->getPaginate();

        $expected = 9;
        $actual   = $page->before;

        $this->assertEquals($expected, $actual, 'Before not correct');

        $expected = 11;
        $actual   = $page->next;

        $this->assertEquals($expected, $actual, 'Next not correct');

        $expected = 20;
        $actual   = $page->last;

        $this->assertEquals($expected, $actual, 'Last not correct');

        $expected = 10;
        $actual   = $page->current;

        $this->assertEquals($expected, $actual, 'Current not correct');

        $expected = 20;
        $actual   = $page->total_pages;

        $this->assertEquals($expected, $actual, 'Total Pages not correct');

        //Last Page
        /*$paginator->setCurrentPage(219);

        $page = $paginator->getPaginate();
        $this->assertEquals(get_class($page), 'stdClass');

        $this->assertEquals(count($page->items), 1);

        $this->assertEquals($page->before, 218);
        $this->assertEquals((int) $page->next, 219);
        $this->assertEquals($page->last, 219);

        $this->assertEquals($page->current, 219);
        $this->assertEquals($page->total_pages, 219);*/
   }
}