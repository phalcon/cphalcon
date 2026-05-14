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

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Translate\Fake\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;

final class ResetDomainTest extends AbstractUnitTestCase
{
    use TranslateGettextTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterGettextResetDomain(): void
    {

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        //Put the good one to get the return textdomain
        $oTextDomainMessage = $translator->setDomain('messages');
        $this->assertSame('Hello', $translator->_('hi'));

        //Check with a domain which does not exist
        $oTextDomainNoExist = $translator->setDomain('no_exist');
        $this->assertSame('hi', $translator->_('hi'));

        $oTextDomainReset = $translator->resetDomain();
        $this->assertSame('Hello', $translator->_('hi'));
        $this->assertNotEquals($oTextDomainNoExist, $oTextDomainReset);
        $this->assertSame($oTextDomainMessage, $oTextDomainReset);
    }
}
