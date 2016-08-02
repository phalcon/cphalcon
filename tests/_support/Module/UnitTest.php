<?php

namespace Phalcon\Test\Module;

use UnitTester;
use Codeception\Specify;
use Codeception\Test\Unit;

/**
 * \Phalcon\Test\Module\UnitTest.php
 * Base class for all Unit tests
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Module
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class UnitTest extends Unit
{
    use Specify;

    /**
     * UnitTester Object
     * @var UnitTester
     */
    protected $tester;

    /**
     * executed before each test
     */
    protected function _before()
    {
    }

    /**
     * executed after each test
     */
    protected function _after()
    {
    }

    /**
     * @return UnitTester
     */
    public function getTester()
    {
        return $this->tester;
    }
}
