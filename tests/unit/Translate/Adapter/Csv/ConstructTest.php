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

use ArrayAccess;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Translate\Fake\FakeCsvFopen;
use Phalcon\Tests\Unit\Translate\Fake\TranslateCsvTrait;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\Csv;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;

use function supportDir;

final class ConstructTest extends AbstractUnitTestCase
{
    use TranslateCsvTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterCsvConstruct(): void
    {

        $language   = $this->getCsvConfig()['en'];
        $translator = new Csv(new InterpolatorFactory(), $language);

        $this->assertInstanceOf(ArrayAccess::class, $translator);
        $this->assertInstanceOf(AdapterInterface::class, $translator);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterCsvContentParamExist(): void
    {

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Parameter 'content' is required");

        (new Csv(new InterpolatorFactory(), []));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterCsvErrorLoadingFile(): void
    {

        $message = "Error opening translation file '" . supportDir('assets/translation/csv/en.csv') . "'";
        $this->expectException(Exception::class);
        $this->expectExceptionMessage($message);

        $language = $this->getCsvConfig()['en'];
        (new FakeCsvFopen(new InterpolatorFactory(), $language));
    }
}
