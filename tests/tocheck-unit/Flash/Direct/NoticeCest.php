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

namespace Phalcon\Test\Unit\Flash\Direct;

use UnitTester;

class NoticeCest
{
    /**
     * Tests Phalcon\Flash\Direct :: notice()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashDirectNotice(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - notice()');

        $I->skipTest('Need implementation');
    }
}
