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

namespace Phalcon\Tests\Unit\Html\Escaper;

use Phalcon\Html\Escaper;
use UnitTester;

use const ENT_HTML401;
use const ENT_QUOTES;
use const ENT_SUBSTITUTE;

/**
 * Class GetSetFlagsCest
 *
 * @package Phalcon\Tests\Unit\Html\Escaper
 */
class GetSetFlagsCest
{
    /**
     * Tests Phalcon\Escaper :: getFlags() / setFlags()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function escaperGetSetFlags(UnitTester $I)
    {
        $I->wantToTest('Escaper - getFlags() / setFlags()');

        $escaper = new Escaper();

        $expected = ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML401;
        $actual   = $escaper->getFlags();
        $I->assertEquals($expected, $actual);

        $escaper->setFlags(ENT_HTML401);

        $expected = ENT_HTML401;
        $actual   = $escaper->getFlags();
        $I->assertEquals($expected, $actual);

        $expected = 'That&#039;s right';
        $actual   = $escaper->attributes("That's right");
        $I->assertEquals($expected, $actual);
    }
}
