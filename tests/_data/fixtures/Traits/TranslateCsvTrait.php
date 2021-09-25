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

namespace Phalcon\Tests\Fixtures\Traits;

use function dataDir;

trait TranslateCsvTrait
{
    protected function getCsvConfig(): array
    {
        return [
            'en' => [
                'content' => dataDir('assets/translation/csv/en.csv'),
            ],
            'es' => [
                'content' => dataDir('assets/translation/csv/es_ES.csv'),
            ],
            'fr' => [
                'content'   => dataDir('assets/translation/csv/fr_FR.csv'),
                'delimiter' => '|',
                'enclosure' => "'",
            ],
            'ru' => [
                'content' => dataDir('assets/translation/csv/ru_RU.csv'),
            ],
        ];
    }
}
