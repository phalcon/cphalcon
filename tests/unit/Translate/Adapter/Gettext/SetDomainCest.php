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

use ArrayAccess;
use Phalcon\Test\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class SetDomainCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: setDomain()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-06
     */
    public function translateAdapterGettextSetDomain(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - setDomain()');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(
            new InterpolatorFactory(),
            $params
        );

        $I->assertEquals('Hello', $translator->_('hi'));

        //Check with a domain which doesn't exist
        $translator->setDomain('no_exist');

        $I->assertEquals('hi', $translator->_('hi'));

        //Put the good one
        $translator->setDomain('messages');

        $I->assertEquals('Hello', $translator->_('hi'));
    }
}
