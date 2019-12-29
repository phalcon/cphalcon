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

namespace Phalcon\Test\Unit\Di\Exception\ServiceResolutionException;

use UnitTester;

class GetPreviousCest
{
    /**
     * Unit Tests Phalcon\Di\Exception\ServiceResolutionException ::
     * getPrevious()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diExceptionServiceResolutionExceptionGetPrevious(UnitTester $I)
    {
        $I->wantToTest('Di\Exception\ServiceResolutionException - getPrevious()');

        $I->skipTest('Need implementation');
    }
}
