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

namespace Phalcon\Test\Unit\Tag;

use UnitTester;

class JavascriptIncludeCest
{
    /**
     * Tests Phalcon\Tag :: javascriptInclude()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function tagJavascriptInclude(UnitTester $I)
    {
        $I->wantToTest('Tag - javascriptInclude()');

        $I->skipTest('Need implementation');
    }
}
