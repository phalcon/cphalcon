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

namespace Phalcon\Tests\Unit\Translate\Adapter\Gettext;

use Phalcon\Tests\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

/**
 * Class ResetDomainCest
 *
 * @package Phalcon\Tests\Unit\Translate\Adapter\Gettext
 */
class ResetDomainCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: resetDomain()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterGettextResetDomain(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - resetDomain()');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        //Put the good one to get the return textdomain
        $oTextDomainMessage = $translator->setDomain('messages');
        $I->assertEquals('Hello', $translator->_('hi'));

        //Check with a domain which doesn't exist
        $oTextDomainNoExist = $translator->setDomain('no_exist');
        $I->assertEquals('hi', $translator->_('hi'));

        $oTextDomainReset = $translator->resetDomain();
        $I->assertEquals('Hello', $translator->_('hi'));
        $I->assertNotEquals($oTextDomainNoExist, $oTextDomainReset);
        $I->assertEquals($oTextDomainMessage, $oTextDomainReset);
    }
}
