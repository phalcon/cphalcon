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

namespace Phalcon\Tests\Models;

use Phalcon\Mvc\Model\Row;
use Phalcon\Mvc\ModelInterface;

use function is_string;


class InvoicesExtended extends Invoices
{
    /**
     * @param array|string|null $parameters
     *
     * @return ModelInterface|Row|null
     */
    public static function findFirst($parameters = null)
    {
        if (is_string($parameters)) {
            return parent::findFirstByInvId($parameters);
        }

        return parent::findFirst($parameters);
    }
}
