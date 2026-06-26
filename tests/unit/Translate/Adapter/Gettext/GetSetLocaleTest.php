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

use function getenv;

final class GetSetLocaleTest extends AbstractUnitTestCase
{
    use TranslateGettextTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterGettextGetSetLocale(): void
    {

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        $expected = 'en_US.utf8';
        $actual   = $translator->getLocale();
        $this->assertSame($expected, $actual);

        /**
         * The constructor's locale is propagated to the environment.
         */
        $this->assertSame('en_US.utf8', getenv('LC_ALL'));

        /**
         * An unavailable locale must leave the environment untouched.
         */
        $translator->setLocale(1, ['ru']);

        $expected = '';
        $actual   = $translator->getLocale();
        $this->assertEquals($expected, $actual);
        $this->assertSame('en_US.utf8', getenv('LC_ALL'));

        $translator->setLocale(1, ['ru_RU.utf8']);

        $expected = 'ru_RU.utf8';
        $actual   = $translator->getLocale();
        $this->assertSame($expected, $actual);

        /**
         * A valid locale is propagated to LC_ALL/LANG/LANGUAGE.
         */
        $this->assertSame('ru_RU.utf8', getenv('LC_ALL'));
        $this->assertSame('ru_RU.utf8', getenv('LANG'));
        $this->assertSame('ru_RU.utf8', getenv('LANGUAGE'));
    }
}
