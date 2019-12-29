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

namespace Phalcon\Test\Unit\Translate\Adapter\Gettext;

use UnitTester;

class SetDomainCest
{
    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: setDomain()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterGettextSetDomain(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - setDomain()');

        $I->skipTest('Need implementation');
    }
}
