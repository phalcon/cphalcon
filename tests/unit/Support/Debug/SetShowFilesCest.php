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

namespace Phalcon\Tests\Unit\Support\Debug;

use UnitTester;

class SetShowFilesCest
{
    /**
     * Tests Phalcon\Debug :: setShowFiles()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportDebugSetShowFiles(UnitTester $I)
    {
        $I->wantToTest('Debug - setShowFiles()');

        $I->skipTest('Need implementation');
    }
}
