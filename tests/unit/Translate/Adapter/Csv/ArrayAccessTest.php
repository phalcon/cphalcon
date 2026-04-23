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

namespace Phalcon\Tests\Unit\Translate\Adapter\Csv;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Translate\Fake\TranslateCsvTrait;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\InterpolatorFactory;

final class ArrayAccessTest extends AbstractUnitTestCase
{
    use TranslateCsvTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterCsvWithArrayAccess(): void
    {

        $language = $this->getCsvConfig()['ru'];

        $translator = new Csv(new InterpolatorFactory(), $language);

        $actual = isset($translator['Hello!']);
        $this->assertTrue($actual);

        $actual = isset($translator['Hi there!']);
        $this->assertFalse($actual);
    }
}
