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

class ResetDomainCest
{
    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: resetDomain()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterGettextResetDomain(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - resetDomain()');

        $I->skipTest('Need implementation');
    }
}
