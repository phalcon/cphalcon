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
 * Class GetSetCustomTemplateCest
 *
 * @package Phalcon\Tests\Unit\Flash\Direct
 */
class GetSetCustomTemplateCest
{
    /**
     * Tests Phalcon\Flash\Direct :: getCustomTemplate()/setCustomTemplate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectGetSetCustomTemplate(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getCustomTemplate()/setCustomTemplate()');

        $flash = new Direct();

        $actual = $flash->getCustomTemplate();
        $I->assertEmpty($actual);

        $template = '<span class="{cssClasses}">{message}</span>';
        $actual   = $flash->setCustomTemplate($template);
        $I->assertInstanceOf(Direct::class, $actual);

        $actual = $flash->getCustomTemplate();
        $I->assertEquals($template, $actual);
    }
}
