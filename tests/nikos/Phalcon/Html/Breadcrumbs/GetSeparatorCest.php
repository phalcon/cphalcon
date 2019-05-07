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

namespace Phalcon\Test\Unit\Html\Breadcrumbs;

use UnitTester;

class GetSeparatorCest
{
    /**
     * Tests Phalcon\Html\Breadcrumbs :: getSeparator()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function htmlBreadcrumbsGetSeparator(UnitTester $I)
    {
        $I->wantToTest('Html\Breadcrumbs - getSeparator()');

        $I->skipTest('Need implementation');
    }
}
