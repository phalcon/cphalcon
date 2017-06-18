<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\Test\Models\DynamicUpdate\Robots;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\Model\DynamicUpdateTest
 * Tests the Phalcon\Mvc\Model component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DynamicUpdateTest extends UnitTest
{
    /**
     * Tests dynamic update create then update
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @issue 12766
     * @since  2017-04-04
     */
    public function testIssue12766()
    {
        $robots = new Robots();
        $robots->name = 'Test';
        $robots->type = 'mechanical';
        $robots->datetime = (new \DateTime())->format('Y-m-d');
        $robots->text = 'text';

        $robots->create();

        $robots->year = 2017;
        $robots->update();
    }
}
