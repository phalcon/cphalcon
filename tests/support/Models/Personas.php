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

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\Model;

/**
 * Class Personas
 */
class Personas extends Model
{
    public string $cedula;
    public int $tipo_documento_id;
    public string $nombres;
    public ?string $telefono = null;
    public float $cupo;
    public string $estado;
}

