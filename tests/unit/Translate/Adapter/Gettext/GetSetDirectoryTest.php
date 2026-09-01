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

use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Translate\Fake\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;

final class GetSetDirectoryTest extends AbstractUnitTestCase
{
    use TranslateGettextTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterGettextGetSetDirectory(): void
    {

        $params = $this->getGettextConfig();

        $translator = new Gettext(new InterpolatorFactory(), $params);

        $expected = Talon::settings()->supportPath('assets/translation/gettext');
        $actual   = $translator->getDirectory();
        $this->assertSame($expected, $actual);

        $translator->setDirectory(Talon::settings()->dataPath() . '/');

        $expected = Talon::settings()->dataPath() . '/';
        $actual   = $translator->getDirectory();
        $this->assertSame($expected, $actual);

        $translator->setDirectory(['en_US.utf8' => Talon::settings()->dataPath() . '/']);

        $expected = ['en_US.utf8' => Talon::settings()->dataPath() . '/'];
        $actual   = $translator->getDirectory();
        $this->assertSame($expected, $actual);
    }
}
