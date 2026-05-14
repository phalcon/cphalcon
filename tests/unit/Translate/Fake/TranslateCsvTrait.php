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

namespace Phalcon\Tests\Unit\Translate\Fake;

use function supportDir;

trait TranslateCsvTrait
{
    protected function getCsvConfig(): array
    {

        return ['en' => ['content' => supportDir('assets/translation/csv/en.csv'),],
            'es' => ['content' => supportDir('assets/translation/csv/es_ES.csv'),],
            'fr' => ['content' => supportDir('assets/translation/csv/fr_FR.csv'),
                'delimiter' => '|',
                'enclosure' => "'",],
            'ru' => ['content' => supportDir('assets/translation/csv/ru_RU.csv'),],];
    }
}
