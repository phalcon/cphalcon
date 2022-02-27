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
use Phalcon\Tests\Fixtures\Di\InitializationAwareComponent;
use UnitTester;

/**
 * Class InitializationAwareCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class InitializationAwareCest
{
    /**
     * Tests Phalcon\Di\Di :: initialization aware interface
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diInitializationAware(UnitTester $I)
    {
        $I->wantToTest('Di - initialization aware interface');

        $di = new Di();

        $I->assertEquals(true, $di->get(InitializationAwareComponent::class)->isInitialized());
    }
}
