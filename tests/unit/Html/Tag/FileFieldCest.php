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

namespace Phalcon\Test\Unit\Html\Tag;

use UnitTester;

/**
 * Class FileFieldCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class FileFieldCest
{
    /**
     * Tests Phalcon\Html\Tag :: fileField()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagFileField(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - fileField()');
        $I->skipTest('Need implementation');
    }
}
