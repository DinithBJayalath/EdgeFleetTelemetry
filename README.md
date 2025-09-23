# EdgeFleetTelemetry
A high-performance daemon that ingests binary GPS/vehicle telemetry packets over TCP/UDP, writes them to log-structured files on disk, builds a memory-mapped index for fast time-range queries, and exposes a CLI + local TCP query API.
