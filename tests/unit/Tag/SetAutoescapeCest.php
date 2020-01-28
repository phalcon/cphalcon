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

namespace Phalcon\Test\Unit\Tag;

use UnitTester;

class SetAutoescapeCest
{
    /**
     * Tests Phalcon\Tag :: setAutoescape()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function tagSetAutoescape(UnitTester $I)
    {
        $I->wantToTest('Tag - setAutoescape()');

        $I->skipTest('Need implementation');
    }
}
