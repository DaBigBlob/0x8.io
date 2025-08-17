export default {
    async fetch() {
      return new Response(__HTML__, {
        headers: { "content-type": "text/html; charset=utf-8" },
        status: 200
      });
    },
  };
  