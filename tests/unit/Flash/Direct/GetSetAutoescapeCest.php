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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Phalcon\Flash\Direct;
use UnitTester;

/**
 * Class GetAutoescapeCest
 *
 * @package Phalcon\Tests\Unit\Flash\Direct
 */
class GetSetAutoescapeCest
{
    /**
     * Tests Phalcon\Flash\Direct :: getAutoescape()/setAutoescape()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectGetSetAutoescape(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getAutoescape()/setAutoescape()');

        $flash = new Direct();

        $actual = $flash->getAutoescape();
        $I->assertTrue($actual);

        $actual = $flash->setAutoescape(false);
        $I->assertInstanceOf(Direct::class, $actual);

        $actual = $flash->getAutoescape();
        $I->assertFalse($actual);
    }
}
