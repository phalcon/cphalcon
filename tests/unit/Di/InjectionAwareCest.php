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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Tests\Fixtures\Di\InjectionAwareComponent;
use UnitTester;

use function spl_object_hash;

/**
 * Class InjectionAwareCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class InjectionAwareCest
{
    /**
     * Tests Phalcon\Di\Di :: injection aware trait
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diInjectionAware(UnitTester $I)
    {
        $I->wantToTest('Di - injection aware trait');

        $container = new Di();
        $component = new InjectionAwareComponent();

        $component->setDI($container);
        $actual = $component->getDI();

        $expected = spl_object_hash($container);
        $actual   = spl_object_hash($actual);
        $I->assertEquals($expected, $actual);
    }
}
