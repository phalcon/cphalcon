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
use UnitTester;

/**
 * Class GetDefaultCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class GetSetDefaultResetCest
{
    /**
     * Unit Tests Phalcon\Di :: getDefault()/setDefault()/reset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetSetDefaultReset(UnitTester $I)
    {
        $I->wantToTest('Di - getDefault()/setDefault()/reset()');

        $class  = Di::class;
        $actual = Di::getDefault();
        $I->assertInstanceOf($class, $actual);

        $container = Di::getDefault();
        $class     = Di::class;
        $I->assertInstanceOf($class, $container);

        // delete it
        Di::reset();

        $actual = Di::getDefault();
        $I->assertNull($actual);

        // set it again
        Di::setDefault($container);

        $actual = Di::getDefault();
        $I->assertInstanceOf($class, $actual);
    }
}
