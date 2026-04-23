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

use function dataDir;
use function supportDir;

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

        $expected = supportDir('assets/translation/gettext');
        $actual   = $translator->getDirectory();
        $this->assertSame($expected, $actual);

        $translator->setDirectory(dataDir());

        $expected = dataDir();
        $actual   = $translator->getDirectory();
        $this->assertSame($expected, $actual);

        $translator->setDirectory(['en_US.utf8' => dataDir()]);

        $expected = ['en_US.utf8' => dataDir()];
        $actual   = $translator->getDirectory();
        $this->assertSame($expected, $actual);
    }
}
