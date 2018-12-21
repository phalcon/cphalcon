<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Kernel;

use UnitTester;

/**
 * Class PreComputeHashKeyCest
 *
 * @package Phalcon\Test\Unit\Kernel
 */
class PreComputeHashKeyCest
{
    /**
     * Tests Phalcon\Kernel :: preComputeHashKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function kernelPreComputeHashKey(UnitTester $I)
    {
        $I->wantToTest("Kernel - preComputeHashKey()");
        $I->skipTest("Need implementation");
    }
}
